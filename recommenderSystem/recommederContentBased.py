import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

columns_names=['user_id','item_id','rating','timestamp']
df = pd.read_csv('u.data',sep='\t',names=columns_names)
movie_titles = pd.read_csv('Movie_Id_Titles')
df = pd.merge(df,movie_titles,on='item_id')

ratings=pd.DataFrame(df.groupby('title')['rating'].mean())
ratings['num of ratings']=pd.DataFrame(df.groupby('title')['rating'].count())

moviemat=df.pivot_table(index='user_id',columns='title',values='rating')

starwars_user_rating = moviemat['Star Wars (1977)']
liarliar_user_rating = moviemat['Liar Liar (1997)']

similar_to_starwars = moviemat.corrwith(starwars_user_rating)
similar_to_liarliar = moviemat.corrwith(liarliar_user_rating)

corr_starwars = pd.DataFrame(similar_to_starwars,columns=['Correlation'])
corr_starwars.dropna(inplace=True)
corr_starwars = corr_starwars.join(ratings['num of ratings'])
result1=corr_starwars[corr_starwars['num of ratings']>100].sort_values('Correlation',ascending=False).head(10)
print("\n\n\nTop 10 Movie recommended if you like star wars")
print(result1)

corr_liarliar = pd.DataFrame(similar_to_liarliar,columns=['Correlation'])
corr_liarliar.dropna(inplace = True)
corr_liarliar=corr_liarliar.join(ratings['num of ratings'])
result2 = corr_liarliar[corr_liarliar['num of ratings']>100].sort_values('Correlation',ascending = False).head(10)
print("\n\n\nTop 10 movies recommended if you like liar liar")
print(result2)
