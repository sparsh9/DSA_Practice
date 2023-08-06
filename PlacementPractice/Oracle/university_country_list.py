import requests

def get_total_pages(country):
    url = f"https://jsonmock.hackerrank.com/api/universities?country={country}"
    response = requests.get(url)
    data = response.json()
    return data.get("total_pages", 0)

def get_universities_by_country(country, page):
    url = f"https://jsonmock.hackerrank.com/api/universities?country={country}&page={page}"
    response = requests.get(url)
    data = response.json()
    return data.get("data", [])

def bestUniversityByCountry(country):
    total_pages = get_total_pages(country)
    
    if total_pages == 0:
        return ""

    lowest_rank = float('inf')
    best_university = ""

    for page in range(1, total_pages + 1):
        universities = get_universities_by_country(country, page)

        for university in universities:
            rank_display = university.get("rank_display", "0").replace(",", "")
            rank = int(rank_display) if rank_display.isdigit() else float('inf')
            
            if rank < lowest_rank:
                lowest_rank = rank
                best_university = university.get("university", "")

    return best_university

# Example usage of the function
country_name = "Switzerland"
result = bestUniversityByCountry(country_name)
print(result)
