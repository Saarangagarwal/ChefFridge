from pymongo import MongoClient
import base64
from main import imageRead

client = MongoClient('mongodb+srv://satsarsab:satsarsab@starterhacks-k3fzz.gcp.mongodb.net/test?retryWrites=true&w=majority')
connect = False

db = client.starterHacks
image = db.image

while(True):
    try:
        imFile = (image.find()[0]['imageString'])

        localVersion = open('image.png', 'wb')
        (localVersion).write(base64.decodebytes(imFile))
        a = image.find()[0]

        image.delete_one(a)
        imageRead()
        
    except:
        pass
        

