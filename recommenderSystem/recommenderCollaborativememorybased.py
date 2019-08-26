import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics.pairwise import pairwise_distances

def predict(ratings, similarity, type='user'):
    if type == 'user':
        mean_user_rating = ratings.mean(axis=1)
        #You use np.newaxis so that mean_user_rating has same format as ratings
        ratings_diff = (ratings - mean_user_rating[:, np.newaxis])
        pred = mean_user_rating[:, np.newaxis] + similarity.dot(ratings_diff) / np.array([np.abs(similarity).sum(axis=1)]).T
    elif type == 'item':
        pred = ratings.dot(similarity) / np.array([np.abs(similarity).sum(axis=1)])
    return pred

columns_name=['user_id','item_id','rating','timestamp'];
df= pd.read_csv('u.data',sep='\t',names=columns_name)

movie_titles = pd.read_csv("Movie_Id_Titles")

df =df.merge(movie_titles,on='item_id')

n_users = df.user_id.nunique()
n_items = df.item_id.nunique()

train_data,test_data = train_test_split(df,test_size=0.25)
train_data_matrix = np.zeros((n_users, n_items))
for line in train_data.itertuples():
    train_data_matrix[line[1]-1, line[2]-1] = line[3]

test_data_matrix = np.zeros((n_users, n_items))
for line in test_data.itertuples():
    test_data_matrix[line[1]-1, line[2]-1] = line[3]

user_similarity = pairwise_distances(train_data_matrix, metric='cosine')
item_similarity = pairwise_distances(train_data_matrix.T, metric='cosine')

pred2=predict(train_data_matrix,user_similarity,'user')
pred2=pd.DataFrame(pred2)
pred2.columns=movie_titles['title']

user_id=int(input("Enter the user id:-"))

user = pred2.iloc[user_id-1,:]

print("Recommended Movies especially for you:-")
user_arranged = user.sort_values(ascending = False)
pred3 =user_arranged[user_arranged>1]
print(pred3)
