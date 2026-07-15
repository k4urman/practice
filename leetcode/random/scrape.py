import requests
import csv
import json
import time

# EIA API configuration
BASE_URL = "https://api.eia.gov/v2"
API_KEY = "5xyyyblAN0oqQkclTMJPEFevmJSZ9i4u6pnpJgkQ"  # Replace with your actual API key

def fetch_data(route, params=None):
    """Fetch data from EIA API route"""
    url = f"{BASE_URL}/{route}"
    if params is None:
        params = {}
    params['api_key'] = API_KEY
    
    try:
        response = requests.get(url, params=params, timeout=30)
        response.raise_for_status()
        return response.json()
    except requests.exceptions.RequestException as e:
        print(f"Error fetching {route}: {e}")
        return None

def explore_route(route):
    """Explore a route to find available child routes"""
    data = fetch_data(route)
    if data and 'response' in data:
        return data['response']
    return None

def get_facet_values(route, facet_name):
    """Get available values for a facet"""
    facet_route = f"{route}/facet/{facet_name}"
    data = fetch_data(facet_route)
    if data and 'response' in data and 'facets' in data['response']:
        return data['response']['facets']
    return []

def fetch_all_data(route, facets=None, max_rows=5000):
    """Fetch all data from a route with pagination"""
    params = {
        'length': 5000,
        'offset': 0
    }
    
    # Add facets if provided
    if facets:
        for facet_key, facet_values in facets.items():
            if isinstance(facet_values, list):
                for value in facet_values:
                    params[f'facets[{facet_key}][]'] = value
            else:
                params[f'facets[{facet_key}][]'] = facet_values
    
    all_data = []
    data_route = f"{route}/data"
    
    while True:
        print(f"  Fetching offset {params['offset']}...")
        result = fetch_data(data_route, params)
        
        if not result or 'response' not in result:
            break
            
        response = result['response']
        if 'data' in response and response['data']:
            batch = response['data']
            all_data.extend(batch)
            print(f"  Retrieved {len(batch)} records (total: {len(all_data)})")
            
            # Check if we got all data
            total = int(response.get('total', 0))
            if len(all_data) >= total or len(batch) < params['length']:
                break
                
            params['offset'] += params['length']
            time.sleep(0.5)  # Be nice to the API
        else:
            break
    
    return all_data

def search_canada_natural_gas():
    """Search for Canada data in natural gas routes"""
    print("\n" + "="*60)
    print("NATURAL GAS DATA")
    print("="*60)
    
    all_data = []
    
    # Natural gas routes to check
    ng_routes = [
        "natural-gas/pri/sum",      # Prices
        "natural-gas/cons/sum",     # Consumption
        "natural-gas/prod/sum",     # Production
        "natural-gas/move/pipe",    # Pipeline movement
        "natural-gas/move/imp",     # Imports
        "natural-gas/move/exp",     # Exports
    ]
    
    for route in ng_routes:
        print(f"\nChecking: {route}")
        
        # First, explore the route to see available facets
        metadata = explore_route(route)
        if not metadata:
            continue
            
        facets_info = metadata.get('facets', [])
        print(f"  Available facets: {[f.get('id') for f in facets_info]}")
        
        # Try to find Canada in common facet types
        canada_found = False
        for facet_info in facets_info:
            facet_id = facet_info.get('id')
            if facet_id in ['duoarea', 'process', 'series', 'country']:
                print(f"  Checking facet: {facet_id}")
                facet_values = get_facet_values(route, facet_id)
                
                # Look for Canada
                canada_values = [
                    v for v in facet_values 
                    if 'canada' in str(v.get('name', '')).lower() or 
                       'canada' in str(v.get('id', '')).lower()
                ]
                
                if canada_values:
                    print(f"  Found Canada options: {canada_values}")
                    canada_found = True
                    
                    for canada_val in canada_values:
                        canada_id = canada_val.get('id')
                        print(f"  Fetching data for {facet_id}={canada_id}")
                        data = fetch_all_data(route, {facet_id: canada_id})
                        if data:
                            for record in data:
                                record['source_route'] = route
                                record['source_category'] = 'natural-gas'
                            all_data.extend(data)
        
        if not canada_found:
            print("  No Canada-specific facet found, trying general fetch...")
            # Try fetching all data and filtering
            data = fetch_all_data(route)
            if data:
                # Filter for Canada mentions
                canada_data = [
                    r for r in data 
                    if any('canada' in str(v).lower() for v in r.values() if v)
                ]
                if canada_data:
                    print(f"  Found {len(canada_data)} Canada records in general data")
                    for record in canada_data:
                        record['source_route'] = route
                        record['source_category'] = 'natural-gas'
                    all_data.extend(canada_data)
    
    return all_data

def search_canada_petroleum():
    """Search for Canada data in petroleum/crude oil routes"""
    print("\n" + "="*60)
    print("PETROLEUM & CRUDE OIL DATA")
    print("="*60)
    
    all_data = []
    
    # Petroleum routes to check
    petro_routes = [
        "petroleum/pri/spt",        # Spot prices
        "petroleum/move/imp",       # Imports
        "petroleum/move/exp",       # Exports
        "petroleum/cons/psup",      # Consumption/Supply
        "petroleum/prod/wcrp",      # Production
        "crude-oil-imports",        # Crude oil imports (if exists)
    ]
    
    for route in petro_routes:
        print(f"\nChecking: {route}")
        
        metadata = explore_route(route)
        if not metadata:
            continue
            
        facets_info = metadata.get('facets', [])
        print(f"  Available facets: {[f.get('id') for f in facets_info]}")
        
        canada_found = False
        for facet_info in facets_info:
            facet_id = facet_info.get('id')
            if facet_id in ['duoarea', 'process', 'series', 'country', 'product']:
                print(f"  Checking facet: {facet_id}")
                facet_values = get_facet_values(route, facet_id)
                
                canada_values = [
                    v for v in facet_values 
                    if 'canada' in str(v.get('name', '')).lower() or 
                       'canada' in str(v.get('id', '')).lower()
                ]
                
                if canada_values:
                    print(f"  Found Canada options: {canada_values}")
                    canada_found = True
                    
                    for canada_val in canada_values:
                        canada_id = canada_val.get('id')
                        print(f"  Fetching data for {facet_id}={canada_id}")
                        data = fetch_all_data(route, {facet_id: canada_id})
                        if data:
                            for record in data:
                                record['source_route'] = route
                                record['source_category'] = 'petroleum'
                            all_data.extend(data)
        
        if not canada_found:
            print("  No Canada-specific facet found, trying general fetch...")
            data = fetch_all_data(route)
            if data:
                canada_data = [
                    r for r in data 
                    if any('canada' in str(v).lower() for v in r.values() if v)
                ]
                if canada_data:
                    print(f"  Found {len(canada_data)} Canada records in general data")
                    for record in canada_data:
                        record['source_route'] = route
                        record['source_category'] = 'petroleum'
                    all_data.extend(canada_data)
    
    return all_data

def save_to_csv(data, filename="eia_canada_energy_data.csv"):
    """Save data to CSV file"""
    if not data:
        print("\nNo data to save!")
        return
    
    # Get all unique keys
    all_keys = set()
    for record in data:
        all_keys.update(record.keys())
    
    fieldnames = sorted(list(all_keys))
    
    with open(filename, 'w', newline='', encoding='utf-8') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(data)
    
    print(f"\n{'='*60}")
    print(f"SUCCESS! Data saved to: {filename}")
    print(f"Total records: {len(data)}")
    print(f"{'='*60}")

def main():
    if API_KEY == "YOUR_API_KEY_HERE":
        print("ERROR: Please set your API key in the script!")
        print("Get a free key at: https://www.eia.gov/opendata/register.php")
        return
    
    print("EIA Canada Energy Data Extractor")
    print("="*60)
    print(f"Using API Key: {API_KEY[:8]}...")
    
    all_data = []
    
    # Search natural gas data
    ng_data = search_canada_natural_gas()
    all_data.extend(ng_data)
    print(f"\nNatural Gas: Found {len(ng_data)} Canada-related records")
    
    # Search petroleum data
    petro_data = search_canada_petroleum()
    all_data.extend(petro_data)
    print(f"Petroleum: Found {len(petro_data)} Canada-related records")
    
    # Save everything
    if all_data:
        save_to_csv(all_data)
        
        # Show sample
        print("\nSample records:")
        for i, record in enumerate(all_data[:3]):
            print(f"\n{i+1}. {record.get('source_category', 'unknown')} - {record.get('source_route', 'unknown')}")
            for key, value in list(record.items())[:6]:
                print(f"   {key}: {value}")
    else:
        print("\nNo Canada-related data found!")
        print("This might mean:")
        print("- The API routes have changed")
        print("- Your API key needs activation")
        print("- Canada data is in different routes")

if __name__ == "__main__":
    main() 
