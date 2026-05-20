import math

def mosteller(w,h):
	return (((w*h)**0.5)/60)
def du_bois(w,h):
	return (0.007184*(w**0.425)*(h**0.725))
def fujimoto(w,h):
	return (0.008883*(w**0.444)*(h**0.663))
def main():
	w = float(input())
	h = float(input())
	print("Mosteller =",round(((w*h)**0.5)/60,5))
	print("Du Bois =",round(0.007184*(w**0.425)*(h**0.725),5))
	print("Fujimoto =",round((0.008883*(w**0.444)*(h**0.663)),5))

exec(input())