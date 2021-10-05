import praw
#importing api credentials:
from jb_creds import reddit_creds
import random 

reddit = praw.Reddit(
    client_id = reddit_creds['client_id'],
    client_secret = reddit_creds['client_secret'],
    password = reddit_creds['password'],
    user_agent = reddit_creds['user_agent'],
    username = reddit_creds['username']
)


def get_reddit_post(sub, sub_filter = None , limit=1, time_filter = None ):

    time_list = ['day','week','month','year', 'all']

    get_sub = reddit.subreddit(sub)

    if limit > 20:
        return False


    elif sub_filter == 'controversial':
        if time_filter in time_list:
            return random.choices([i.url for i in reddit.subreddit(sub).controversial(time_filter= time_filter)], k = limit)

        return [i.url for i in get_sub.controversial(limit = limit)]

    elif sub_filter == 'top':
        if time_filter in time_list:
            return random.choices([i.url for i in reddit.subreddit(sub).top(time_filter= time_filter)], k = limit)

        return [i.url for i in get_sub.top(limit = limit)]
    

    elif sub_filter == 'hot':
        return [i.url for i in get_sub.hot(limit = limit)]


    elif sub_filter == 'new':
        return [i.url for i in get_sub.new(limit = limit)]

    
    elif sub_filter == 'rising':
        return [i.url for i in get_sub.rising(limit = limit)]
    
    
    else: 
        new_limit = int(sub_filter)
        if new_limit < 21:
            return [get_sub.random().url for i in range(0, new_limit)]
        return False




