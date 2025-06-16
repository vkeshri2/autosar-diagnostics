import json

dids = {
    "DIDs": {
        "F190": {
            "description": "VIN",
            "length": 17
        }
    }
}

with open('../config/dids_config.json', 'w') as f:
    json.dump(dids, f, indent=2)

print("DID config generated.")
