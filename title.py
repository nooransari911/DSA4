from urllib.request import urlopen
from bs4 import BeautifulSoup
import urllib


url = input ("Enter url: ")
heads = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36"}
req = urllib.request.Request(url, headers=heads)
html_page = urllib.request.urlopen(req)
soup = BeautifulSoup(html_page, 'html.parser')
title = soup.title.string

print(title)
print (soup.title)

print (f"[{title}] ({url})")
