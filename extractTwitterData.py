# Twitter Developer account Application credentials
client_key = 'API-key'
client_secret = 'API-secret'

# Ouath2 authentication
import base64
key_secret = '{}:{}'.format(client_key, client_secret).encode('ascii')
b64_encoded_key = base64.b64encode(key_secret)
b64_encoded_key = b64_encoded_key.decode('ascii')

#Post request to obtain a Bearer Token to be included in subsequent API requests.
import requests
base_url = 'https://api.twitter.com/'
auth_url = '{}oauth2/token'.format(base_url)
auth_headers = {
    'Authorization': 'Basic {}'.format(b64_encoded_key),
    'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8'
}
auth_data = {
    'grant_type': 'client_credentials'
}
auth_resp = requests.post(auth_url, headers=auth_headers, data=auth_data)

# Check status code okay (It should be 200)
auth_resp.status_code

# Keys in data response are token_type (bearer) and access_token (your access token)
auth_resp.json().keys()

access_token = auth_resp.json()['access_token']

#We will be making a search request for the keywords mentioned.
search_headers = {
    'Authorization': 'Bearer {}'.format(access_token)    
}
search_params = {
    'q': 'Online Classes covid-19 USA'
}
search_url = '{}1.1/search/tweets.json'.format(base_url)
search_resp = requests.get(search_url, headers=search_headers, params=search_params)
tweet_data = search_resp.json()

#print the text of the tweet
for x in tweet_data['statuses']:
    print(x['text'] + '\n')
