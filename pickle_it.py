import pickle	#import the pickle module

data = [1,2,3,4,5,6,77,8,86,6]	#The data to be pickled

with open('pickledfile.pickle','wb+') as fil:  #Dumping the data means to convert human readable format to bytes. This is called serialisation
    pickle.dump(data,fil)

with open(filename + '.pickle' , 'rb+') as fil: #Loading the data means to convert bytes to human readable format. This is called deserialisation
    p = pickle.load(fil)

# print(unpickle_the_data('pickledfile'))
