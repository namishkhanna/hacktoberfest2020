import requests
import urllib.parse

class Spotify(object):
  def __init__(self, api_token):
    self.api_token = api_token

  def search_song(self, artist, track):
    query = urllib.parse.quote(f'{artist} {track}')
    endpoint = f"https://api.spotify.com/v1/search?q={query}&type=track"
    response = requests.get(
      endpoint,
      headers={
        "Content-Type": "application/json",
        "Authorization": f"Bearer {self.api_token}"
      }
    )
    response_json = response.json()

    results = response_json['tracks']['items']
    if results:
      # assuming the first track in the list is the desired one
      return results[0]['id']
    else:
      raise Exception(f"No song found for {artist}: {track}")

  def add_song_to_spotify(self, song_id):
    endpoint = "Https://api.spotify.com/v1/me/tracks"
    response = requests.put(
      endpoint,
      json={
        "ids": [song_id]
      },
      headers={
        "Content-Type": "application/json",
        "Authorization": f"Bearer {self.api_token}"
      }
    )
    
    return response.ok