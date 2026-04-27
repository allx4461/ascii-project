from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
import requests

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods=["*"],
    allow_headers=["*"],
)

@app.get("/excuse")
def get_excuse():
    try:
        response = requests.get("https://excuser-three.vercel.app/v1/excuse")
        data = response.json()
        return {"excuse": data[0]['excuse']}
    except:
        return {"excuse": "something went wrong :("}