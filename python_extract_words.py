import PyPDF2 
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
import matplotlib.pyplot as plt
from wordcloud import WordCloud, STOPWORDS
import pandas as pd

# Python code to extract words from a PDF file
# and store it in a list

terms = {}
words = []

filename = 'book.pdf'
with open(filename,'rb') as pdfFileObj:
    pdfReader = PyPDF2.PdfFileReader(pdfFileObj)
    num_pages = pdfReader.numPages
    page = pdfReader.getPage(10)
    page_content = page.extractText()

    stemmer = PorterStemmer()

    for i in range(num_pages):
        page = pdfReader.getPage(i)
        page_content = page.extractText()
        tokens = word_tokenize(page_content)
        stop_words = set(stopwords.words('english'))
        filtered_sentence = [stemmer.stem(w.lower()).strip() for w in tokens if not w.lower() in stop_words and 3 < len(w) < 20]
        for word in filtered_sentence:
            if word not in terms:
                terms[word] = 1
            else:
                terms[word] += 1

    terms = sorted(terms.items(), key=lambda x: x[1], reverse=True)
    print(terms)

    terms = [term for term in terms if term[1] > 3]
    print(terms)
    print(len(terms))

    wordcloud = WordCloud(width = 800, height = 800,
                background_color ='white',
                stopwords = stopwords,
                min_font_size = 10).generate(terms)
    # Create graph
    x, y = zip(*terms)
    plt.plot(x, y)
    plt.xlabel('Terms')
    plt.ylabel('Frequency')

    plt.xticks([])
    plt.show()

    # WordCloud
    plt.figure(figsize = (8, 8), facecolor = None)
    plt.imshow(wordcloud)
    plt.axis("off")
    plt.tight_layout(pad = 0)
 
    plt.show()
