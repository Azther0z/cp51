def no_lowercase(t):
    for i in t:
        if 'a'<=i and i<='z':
            return False
    return True
 
def no_uppercase(t):
    for i in t:
        if 'A'<=i and i<='Z':
            return False
    return True
 
def no_number(t):
    for i in t:
        if '0'<=i and i<='9':
            return False
    return True
 
def no_symbol(t):
    for i in t:
        if not('a'<=i and i<='z') and not('A'<=i and i<='Z') and not('0'<=i and i<='9'):
            return False
    return True
 
def character_repetition(t): 
    for i in range(len(t)-3):
        tmp = t[i:i+4]
        check = True
        for j in tmp:
            if j!=tmp[0]:
                check = False
                break
        if check:
            return True
    return False
 
def number_sequence(t): 
    src = '01234567890'
    for i in range(len(t)-3):
        if t[i:i+4] in src or t[i:i+4] in src[::-1]:
            return True
    return False
 
def letter_sequence(t):
    t = t.lower() 
    src = 'abcdefghijklmnopqrstuvwxyz'
    for i in range(len(t)-3):
        if t[i:i+4] in src or t[i:i+4] in src[::-1]:
            return True
    return False
 
def keyboard_pattern(t):
    t = t.lower() 
    src = ['!@#$%^&*()_+',
            'qwertyuiop',
            'asdfghjkl',
            'zxcvbnm']
    for i in range(len(t)-3):
        for j in src:
            if t[i:i+4] in j or t[i:i+4] in j[::-1]:
                return True
    return False
 
password = input().strip() 
error = [] 
if len(password) < 8: 
    error.append('Less than 8 characters') 
if no_lowercase(password): 
    error.append('No lowercase letters') 
if no_uppercase(password): 
    error.append('No uppercase letters')
if no_number(password):
    error.append('No numbers')
if no_symbol(password):
    error.append('No symbols')
if character_repetition(password):
    error.append('Character repetition')
if number_sequence(password):
    error.append('Number sequence')
if letter_sequence(password):
    error.append('Letter sequence')
if keyboard_pattern(password):
    error.append('Keyboard pattern')
if len(error) == 0: 
    print('OK') 
else: 
    for e in error:
        print(e)