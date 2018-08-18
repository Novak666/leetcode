import numpy as np
#import tensorflow as tf

'''
hello = tf.constant('Hello, TensorFlow!')
sess = tf.Session()
print(sess.run(hello))
tensor = [[[1, 2], [3, 4], [5, 6]]]
mask = np.array([[[True, True], [True, True], [False, False]]])

print(sess.run(tf.boolean_mask(tensor, mask)))
'''
a = 3
b = 4
x = a if a > b else b
print(x)
