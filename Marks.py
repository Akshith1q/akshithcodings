print("Enter number of marks")
a=int(input())
marks=[]
print("Enter the marks:")
for i in range(a):
    mark=int(input(""))
    marks.append(mark)
print("Current marks:",marks)
position=int(input("Which mark number do you want to change? "))-1
new_mark=int(input("Enter the new mark:"))
marks[position]=new_mark
print("Updated marks:",marks)