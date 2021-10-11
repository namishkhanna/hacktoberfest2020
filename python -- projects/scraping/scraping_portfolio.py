
import requests
from bs4 import BeautifulSoup
url = "https://viveena.netlify.app"

# Step 1: Get the HTML
r = requests.get(url)
htmlContent = r.content
print(htmlContent)

# Step 2: Parse the HTML
soup = BeautifulSoup(htmlContent, 'html.parser')
print(soup.prettify)
print(soup)

title = soup.title

print(type(title)) # 1. Tag
print(type(title.string)) # 2. NavigableString
print(type(soup)) # 3. BeautifulSoup


# Get all the paragraphs from the page
paras = soup.find_all('p')
print(paras)


# Get first element in the HTML page
print(soup.find('p') ) 

# Get classes of any element in the HTML page
print(soup.find('p')['class'])

# find all the elements with class container
print(soup.find_all("p", class_="container"))

# Get all the anchor tags from the page
anchors = soup.find_all('a')
all_links = set()
# Get all the links on the page:
for link in anchors:
    if(link.get('href') != '#'): 
    #     linkText = "https://viveena.netlify.app/" +link.get('href')
    #     all_links.add(link)
        print(link.get('href'))