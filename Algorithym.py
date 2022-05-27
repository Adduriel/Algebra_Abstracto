from cryptography.fernet import Fernet 
  
  
key = Fernet.generate_key() 
  
f = Fernet(key) 
  
token = f.encrypt(b"Este es un mensaje secreto") 
  
print(token) 
  
d = f.decrypt(token) 
  
print(d.decode()) 