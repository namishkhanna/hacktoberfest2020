# Youtube management class
import os
import google_auth_oauthlib
import googleapiclient
import youtube_dl

from song import Song
from playlist import Playlist


class Youtube(object):
  def __init_(self, credentials_location):
    scopes = ["https://www.googleapis.com/auth/youtube.readonly"]

    # Disable OAuthlib's HTTPS verification when running locally.
    # *DO NOT* leave this option enabled in production.
    os.environ["OAUTHLIB_INSECURE_TRANSPORT"] = "1"

    api_service_name = "youtube"
    api_version = "v3"

    # Get credentials and create an API client
    flow = google_auth_oauthlib.flow.InstalledAppFlow.from_client_secrets_file(
        credentials_location, scopes)
    credentials = flow.run_console()
    youtube = googleapiclient.discovery.build(
        api_service_name, api_version, credentials=credentials)

    self.youtube_client = youtube_client


def get_playlists(self):
  request = self.youtube_client.playlist().list(
    part = "id, snippet",
    maxResult = 50,
    mine = True
  )
  fetched_playlist = request.execute()
  playlists = [Playlist(
    item['id'], 
    item['snippet']['title']
    ) for item in fetched_playlist['items']]

  return playlists
  

def get_videos_from_playlist(self, playlist_id):
  songs = []
  request = self.youtube_client.playlistItems().list(
    playlistId = playlist_id,
    part = "id, snipper"
  )

  fetched_videos = request.execute()

  for item in fetched_videos['items']:
    video_id = item['snippet']['resourceId']['videoId']
    artist, track = self.get_artist_and_track_from_video(video_id)
    if artist and track:
      songs.append(Song(artist, track))

def get_artist_and_track_from_video(self, video_id):
  youtube_url = f"https://www.youtube.com/watch?v={video_id}"

  video = youtube_dl.YoutubeDL({'quiet': True}).extract_info(
    youtube_url, download=False
  )

  artist = video['artist']
  track = video['track']

  return artist, track