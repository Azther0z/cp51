def sqrt_n_times(x, n):   
# คืนค่าที่เสมือนการน าค่าใน x มากดปุ ่ม    เป็นจ านวน n ครั ้ง 
	return x**(1/(2**n))
def cube_root(y):  
# คืนค่าประมาณของรากที่สามของ y โดยใชวิธีที่เสมือนการกดปุ ่มด้วยสูตร 
	a = sqrt_n_times(y,2)
	b = a*sqrt_n_times(a,2)
	c = b*sqrt_n_times(b,4)
	d = c*sqrt_n_times(c,8)
	e = d*sqrt_n_times(d,16)
	f = e*sqrt_n_times(e,32)
	return f
# ข้อแนะน า: เรยกใชฟงกชน sqrt_n_times   
def main(): 
	q = float(input()) 
	print(cube_root(q)) 
exec(input()) # DON'T remove this line