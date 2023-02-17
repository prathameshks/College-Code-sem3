class HashTable_NoCollision:
	hash_table = []
	def __init__(self):
		self.m = int(input("Enter size of Hash Table:"))
		
		# Initializing hash table
		for i in range(self.m):
			self.hash_table.append(0)
		
	def hash_function(self,x):
		key = x % self.m
		return key
		
	def initialize(self,arr):
		for i in range(len(arr)):
			key = self.hash_function(arr[i])
			self.hash_table[key] = arr[i]
			
	def display(self):
		print("\nKey - Value")
		for i in range(self.m):
			print(i,'-',self.hash_table[i])
		
class HashTable_Collision1:
	#put collision element on next empty spot
	hash_table = []
	def __init__(self):
		self.m = int(input("Enter size of Hash Table:"))
		
		# Initializing hash table
		for i in range(self.m):
			self.hash_table.append(0)
		
	def hash_function(self,x):
		key = x % self.m
		return key
		
	def initialize(self,arr):
		for i in range(len(arr)):
			key = self.hash_function(arr[i])
			while(self.hash_table[key] != 0):
				key = (key + 1) % self.m
			self.hash_table[key] = arr[i]
			
	def display(self):
		print("\nKey - Value")
		for i in range(self.m):
			print(i,'-',self.hash_table[i])



def main():
	table = HashTable_Collision1()
	
	# Accepting array elements
	n = int(input("Enter number of elements in array:"))
	s = []
	for i in range(n):
		elmt = int(input(f"Enter element ({i}):"))
		s.append(elmt)
	
	table.initialize(s)
	table.display()
	
	
main()
		


	