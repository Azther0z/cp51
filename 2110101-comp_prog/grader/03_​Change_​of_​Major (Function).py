def choose(stu1,stu2):
	if(stu1[2]=="A" and stu1[3]<="C" and stu1[4]<="C") and (stu2[2]=="A" and stu2[3]<="C" and stu2[4]<="C"):
		if stu1[1]<stu2[1]:
			return [stu2[0]]
		elif stu1[1]>stu2[1]:
			return [stu1[0]]
		elif stu1[3]<stu2[3]:
			return [stu1[0]]
		elif stu1[3]>stu2[3]:
			return [stu2[0]]
		elif stu1[4]<stu2[4]:
			return [stu1[0]]
		elif stu1[4]>stu2[4]:
			return [stu2[0]]
		else:
			return [stu1[0],stu2[0]]
	if(stu1[2]=="A" and stu1[3]<="C" and stu1[4]<="C"):
		return [stu1[0]]
	if(stu2[2]=="A" and stu2[3]<="C" and stu2[4]<="C"):
		return [stu2[0]]


	return []




exec(input())