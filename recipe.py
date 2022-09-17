import requests

def getDish(inp):
    api_key = '9a6433b6a3f4712abf24deaeaee2550e'
    app_id = '5bbd72df'
    foods = []
    
    for ingredient in inp:
        response = requests.get('https://api.edamam.com/search?q=' + ingredient.lower() + '&app_id=' + app_id + '&app_key=' + api_key)
        json_response = response.json()
        for recipe in(json_response['hits']):
            foods.append(recipe['recipe']['label'])
            
    return foods

