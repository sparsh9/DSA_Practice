# Importing the Dependencies
import re
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns
import nltk

# Importing From ....
from collections import Counter
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from scipy.stats import linregress
from wordcloud import WordCloud


# Downloading
nltk.download('stopwords')

# Count Function to Count the Frequency of words
def count_word(file_name):
    with open(file_name,encoding='utf8') as file:
        return Counter(file.read().split())

# Function To Read The Text Files.
def read_book(file_name):
    file = open(file_name, 'r')
    f_data = file.read().lower()
    f_words = f_data.split()
    number_of_words = len(f_words)
    # print(f_words)
    print("Number of Words in the text file is : ", number_of_words)
    file.close()
    return f_words


# Function to filter out some of the words obtained from the file.
def file_filter(words):
    words = [word.replace("’s","") for word in words]
    words = [re.sub(r'[^a-zA-Z0-9]', " ", word) for word in words]
    # print(words)
    with open(r'WordList.txt', 'w', encoding='utf8') as wf:
        for word in words:
            wf.write("%s\n" %word)
    return words

# Function to apply the Porter Stemmer to the filtered words.
def porter_stemmer(words):
    ps = PorterStemmer()
    words = [ps.stem(word) for word in words]
    with open(r'stemmer.txt','w',encoding='utf8') as sf:
        for word in words:
            sf.write("%s\n" %word)

# Function for Fitting the Plot to the linear relation.
def linear_regression(df):
    fig,ax = plt.subplots()
    x_lr = df['Rank'].values
    y_lr = df['Log_Feq'].values
    plt.scatter(x_lr,y_lr,color="m",marker="o",s=30)
    res1 = linregress(x_lr,y_lr)
    ax.plot(x_lr,res1.intercept+res1.slope*x_lr,'r')
    plt.savefig('linear_regression.png',dpi=500)
    plt.show()

    # Printing results of Alpha and k in ln(f) = -(alpha)*ln(r) + k
    print("---------------------------------------------------")
    print("Alpha =", res1.slope)
    print("k =", res1.intercept)
    print("---------------------------------------------------")

    return

# Function to Graph the frequency of the words that are stemmed.
def fre_graph(file_name):
    word_freq = count_word(file_name)
    feq_df = pd.DataFrame(list(word_freq.items()),columns=["Word","Frequency"])
    feq_df["Log_Feq"]=feq_df['Frequency'].apply(lambda x:np.log(x))
    feq_df["Rank"]=feq_df['Frequency'].rank(ascending=False)
    feq_df.sort_values(by='Frequency',ascending=False,inplace=True)
    print(feq_df)
    Freq_Graph = sns.lineplot(x='Word',y='Log_Feq',data=feq_df)
    Freq_Graph.axes.xaxis.set_ticklabels([])
    plt.xticks([])
    plt.ylim(-1,10)
    plt.savefig('frequency_graph.png',dpi=500)
    plt.show()
    linear_regression(feq_df)
    return word_freq

# Function for making the word Cloud.
def Word_Cloud(word_freq):
    filtered = {}
    for word in word_freq:
        if word not in stopwords.words('english'):
            filtered[word] = word_freq[word]


    word_cloud = WordCloud(background_color='white', max_words=200, max_font_size=50).generate_from_frequencies(filtered)
    plt.figure(figsize=(10, 8), facecolor=None)
    plt.imshow(word_cloud)
    plt.savefig('word_cloud.png')
    plt.show()

# Main Function / Driver Function.
if __name__ == '__main__':
    book = 'Sherlock.txt'
    words = read_book(book)
    filter_words = file_filter(words)
    porter_stemmer(filter_words)
    word_frequency=fre_graph("stemmer.txt")
    Word_Cloud(word_frequency)

