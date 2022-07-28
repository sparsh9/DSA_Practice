import PyPDF2 
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords

# Python code to extract words from a PDF file
# and store it in a list


filename = 'sample.pdf'
pdfFileObj = open(filename,'rb')

pdfReader = PyPDF2.PdfFileReader(pdfFileObj)
num_pages = pdfReader.numPages
page = pdfReader.getPage(0)
page_content = page.extractText()

print(page_content, num_pages)
