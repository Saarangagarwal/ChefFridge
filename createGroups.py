import json
import pickle

output = {'BLUEBERRY', 'CRANBERRY', 'HUCKLEBERRY', 'COD', 'HAKE', 'CRAB APPLE', 'PERCH-LIKE FISHES',
	'BEEF', 'VEAL', 'CAPSICUM', 'BONITO', 'MACKEREL', 'TUNA', 'COMMON HALIBUT', 'CHERRY', 'PLUM', 
	'BLACKBERRY', 'RASPBERRY', 'PIGLET', 'PORK', 'CLEMENTINE', 'TANGERINE', 'ONION', 'MINT','ORANGE'}
with open('Food_Database/foods.json', encoding='utf-8-sig') as file:
	data = json.load(file)
	for sub in data:
		output.add(sub["name"].upper())
output.remove("VEGETARIAN FOOD")
with open('inputFiles/foodData.pickle', 'wb') as f:
	pickle.dump(output, f)

