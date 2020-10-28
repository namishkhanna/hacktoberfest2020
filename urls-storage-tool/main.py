from dotenv import load_dotenv
from os import getenv
from sys import argv

from db import Database

load_dotenv()

if len(argv) > 1 and argv[1] == 'db-setup':
  '''
    Initialize DB
    Usage: python main.py db-setup
  '''
  print('Creating table in database...')
  db = Database(getenv('DB_NAME'))
  db.create_table('CREATE TABLE urls (id INTEGER PRIMARY KEY AUTOINCREMENT, category TEXT, url TEXT)')


if len(argv) > 1 and argv[1] == 'insert':
  '''
  Insert record into Db
  Usage: python main.py insert
  '''
  print('Adding new url address...')
  category = argv[2]
  url = argv[3]
  db = Database(getenv('DB_NAME'))
  db.insert('urls', None, category, url)

if len(argv) > 1 and argv[1] == 'list':
  '''
  Fetch all records from desired category
  Usage: python main.py list {category-name}
  '''
  print(f'List of links from category {argv[2]}:')
  category = argv[2]
  db = Database(getenv('DB_NAME'))
  links = db.fetch_all('urls', category=category)
  for link in links:
    print(link[2])