from dotenv import load_dotenv
from os import getenv

from yt import Youtube
from spotify import Spotify

load_dotenv()

def run():

  # Get a list of playlists from yt
  youtube = Youtube('./credentials/client_secrets.json')
  spotify = Spotify(getenv('SPOTIFY_OAUTH_TOKEN'))
  playlists = youtube.get_playlists()
  
  # Ask which playlist we want to get the music videos from
  for index, playlist in enumerate(playlists):
    print(f"{index}: {playlist.title}")
  choice = int(input("Enter desired playlist number: "))
  chosen_playlist = playlists[choice]
  print(f"Selected playlist name: {chosen_playlist.title}")
  
  # For each video in the playlist get the song info from yt
  songs = youtube.get_videos_from_playlist(chosen_playlist.id)
  print(f"Attempting to add {len(songs)}")
  
  # Search for desired song on Spotify
  for song in songs:
    spotify_song_id = spotify.search_song(song.artist, song.track)
    if spotify_song_id:
      added_song = spotify.add_song_to_spotify(spotify_song_id)
      if added_song:
        print(f"Successfully added {song.artist} to Spotify liked songs")

  # Having found the desired song, add it to Spotify liked Songs

if __name__ == '__main__':
  run()
