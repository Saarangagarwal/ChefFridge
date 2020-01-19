import io
import os
from google.cloud import vision
from google.cloud.vision import types
import pickle
from recipe import getDish

def imageRead():
    client = vision.ImageAnnotatorClient()

    fileName = os.path.abspath('image.png')
    with io.open(fileName, 'rb') as imageFile:
        content = imageFile.read()

    image = types.Image(content= content)

    response = client.label_detection(image=image)

    labels = response.label_annotations

    limit = 0

    predictions = []
    
    for label in labels:
        if label.score > limit:
            predictions.append(label.description.upper())
    foodInfo = pickle.load(open("inputFiles/foodData.pickle", "rb"))
    actualPred = set()
    for i in predictions:
        if i in foodInfo:
            actualPred.add(i)
    actualPred = list(actualPred)
    print("In your Fridge:")
    print(actualPred)
    print("Recipes:")
    print(getDish(actualPred))
