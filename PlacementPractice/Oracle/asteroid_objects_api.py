import requests

def get_asteroids_designation(orbit_class, year):
    # Retrieve data from the API and get the total number of pages
    r = requests.get("http://jsonmock.hackerrank.com/api/asteroids/search?page="+str(1)).json()
    total_pages = r['total_pages']

    # Initialize an empty list for storing data
    data_list = []

    # Loop through all the pages and retrieve data
    for i in range(1, total_pages + 1):
        req = requests.get("http://jsonmock.hackerrank.com/api/asteroids/search?page="+str(i)).json()
        # Correct the indentation of the following block
        for j in req['data']:
            # Check for matching conditions and append to the list
            if str(year) == j['discovery_date'] and orbit_class.lower() in j['orbit_class'].lower():
                if j.get('period_yr') is None:
                    j['period_yr'] = 1
                else:
                    j['period_yr'] = float(j['period_yr'])
                data_list.append(j)

    # Sort the list based on 'period_yr' and 'designation' keys
    data_list.sort(key=lambda x: (x['period_yr'], x['designation']))

    # Create a list to store the 'designation' values
    desg = []

    # Append 'designation' values to the 'desg' list
    for i in data_list:
        desg.append(i['designation'])

    return desg

# Example usage of the function
orbit_class = "aten"
year = 2010
result = get_asteroids_designation(orbit_class, year)
print(result)
  