# Youtube management class
import os

import google_auth_oauthlib
import googleapiclient

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
  fetch_playlist = request.execute()
  playlists = [playlist for playlist in fetch_playlist['items']]
  return playlists
  

def get_videos_from_playlist(self, playlist_id):
  pass

def get_artist_and_track_from_video(self, video_id):
  pass