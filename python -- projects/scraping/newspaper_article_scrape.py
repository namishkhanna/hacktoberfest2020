from newspaper import Article

#A new article from TOI
url = "http://timesofindia.indiatimes.com/world/china/chinese-expert-warns-of-troops-entering-kashmir/articleshow/59516912.cms"

#For different language newspaper refer above table
toi_article = Article(url, language="en") # en for English

#To download the article
toi_article.download()

#To parse the article
toi_article.parse()

#To perform natural language processing ie..nlp
toi_article.nlp()

#To extract title
print("Article's Title:")
print(toi_article.title)
print("n")

#To extract text
print("Article's Text:")
print(toi_article.text)
print("n")

#To extract summary
print("Article's Summary:")
print(toi_article.summary)
print("n")

#To extract keywords
print("Article's Keywords:")
print(toi_article.keywords)
