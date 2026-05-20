def is_mobile_number(number): 
    # number เป็นสตริงเก็บหมายเลข (ภายในสตริงมีแต่ตัวเลขแน่ ๆ) 
    # คืน True ถ้า number เปนหมายเลขโทรศพท ถาไมเปน คน False
    if(len(number)!=10):
        return False
    if number[0:2]=="06" or number[0:2]=="08" or number[0:2]=="09":
        return True
    return False 
 
exec(input()) # DON'T remove this line 