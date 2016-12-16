import os
class SquareSpot(object):
	signInSquare = ' '
	def __init__(self, number):
		self.squarenumber = number

	def getSqNumber(self):
		return self.squarenumber

	def getSqSign(self):
		return self.signInSquare

	def setsign(self, sign):
		self.signInSquare = sign

	def isSpace(self):
		if self.signInSquare == ' ':
			return True
		return False

sq1 = SquareSpot(1)
sq2 = SquareSpot(2)
sq3 = SquareSpot(3)
sq4 = SquareSpot(4)
sq5 = SquareSpot(5)
sq6 = SquareSpot(6)
sq7 = SquareSpot(7)
sq8 = SquareSpot(8)
sq9 = SquareSpot(9)


def drawgrid():
	breadth = 1
	length = 0
	while length < 15:
		if length == 2 or length == 7 or length == 12:
			sqsign1 = 'f'
			sqsign2 = 'f'
			sqsign3 = 'f'
			if length == 2:
				sqsign1 = sq1.getSqSign()
				sqsign2 = sq2.getSqSign()
				sqsign3 = sq3.getSqSign()
			elif length == 7:
				sqsign1 = sq4.getSqSign()
				sqsign2 = sq5.getSqSign()
				sqsign3 = sq6.getSqSign()
			else:
				sqsign1 = sq7.getSqSign()
				sqsign2 = sq8.getSqSign()
				sqsign3 = sq9.getSqSign()
			print ("    ", sqsign1, "    ", sqsign2, "    ", sqsign3)
			breadth+=1
			length+=1
			continue
		print ("         |         |")
		if breadth == 5 or breadth == 10:
			print ("-------------------------------")
		breadth+=1
		length+=1

def reset():
	sq1.setsign(' ')
	sq2.setsign(' ')
	sq3.setsign(' ')
	sq4.setsign(' ')
	sq5.setsign(' ')
	sq6.setsign(' ')
	sq7.setsign(' ')
	sq8.setsign(' ')
	sq9.setsign(' ')

def checkDraw():
	if sq1.getSqSign() == ' ' or sq2.getSqSign() == ' ' or sq3.getSqSign() == ' ' or sq4.getSqSign() == ' ' or sq5.getSqSign() == ' ' or sq6.getSqSign() == ' ' or sq7.getSqSign() == ' ' or sq8.getSqSign() == ' ' or sq9.getSqSign() == ' ':
		return False
	return True

def clearscreen():
	os.system('cls' if os.name == 'nt' else 'clear')

def checkTrio():
	if sq1.getSqSign()!=' ' and sq1.getSqSign() == sq2.getSqSign() and sq2.getSqSign() == sq3.getSqSign():
		return True
	elif sq1.getSqSign() != ' ' and sq1.getSqSign() == sq4.getSqSign() and sq4.getSqSign() == sq7.getSqSign():
		return True
	elif sq1.getSqSign() != ' ' and sq1.getSqSign() == sq5.getSqSign() and sq5.getSqSign() == sq9.getSqSign():
		return True
	elif sq4.getSqSign() != ' ' and sq4.getSqSign() == sq5.getSqSign() and sq5.getSqSign() == sq6.getSqSign():
		return True
	elif sq7.getSqSign() != ' ' and sq7.getSqSign() == sq8.getSqSign() and sq8.getSqSign() == sq9.getSqSign():
		return True
	elif sq2.getSqSign() != ' ' and sq2.getSqSign() == sq5.getSqSign() and sq5.getSqSign() == sq8.getSqSign():
		return True
	elif sq3.getSqSign() != ' ' and sq3.getSqSign() == sq6.getSqSign() and sq6.getSqSign() == sq9.getSqSign():
		return True
	elif sq3.getSqSign() != ' ' and sq3.getSqSign() == sq5.getSqSign() and sq5.getSqSign() == sq7.getSqSign():
		return True
	return False

def PlayTurn(playerNumber, playerChar):
	posEntered=0
	while True:
		print("")
		print ("Player ", playerNumber, " enter a grid position from 1 to 9 : ")
		posEntered = int(input())
		if posEntered < 1 or posEntered > 9:
			print ("Wrong position entered! Try again")
		else:
			break
	print ("Check")
	if posEntered == 1:
		if sq1.isSpace() == True:
			sq1.setsign(playerChar)
		else:
			return False
	elif posEntered == 2:
		if sq2.isSpace() == True:
			sq2.setsign(playerChar)
		else:
			return False
	elif posEntered == 3:
		if sq3.isSpace() == True:
			sq3.setsign(playerChar)
		else:
			return False
	elif posEntered == 4:
		if sq4.isSpace() == True:
			sq4.setsign(playerChar)
		else:
			return False
	elif posEntered == 5:
		if sq5.isSpace() == True:
			sq5.setsign(playerChar)
		else:
			return False
	elif posEntered == 6:
		if sq6.isSpace() == True:
			sq6.setsign(playerChar)
		else:
			return False
	elif posEntered == 7:
		if sq7.isSpace() == True:
			sq7.setsign(playerChar)
		else:
			return False
	elif posEntered == 8:
		if sq8.isSpace() == True:
			sq8.setsign(playerChar)
		else:
			return False
	elif posEntered == 9:
		if sq9.isSpace() == True:
			sq9.setsign(playerChar)
		else:
			return False
	return True

drawgrid()
turn = 1
while True:
	if turn % 2 == 1:
		turnPlayed = PlayTurn(1, 'X')
	else:
		turnPlayed = PlayTurn(2, 'O')
	if turnPlayed == False:
		clearscreen()
		drawgrid()
		print ("")
		print ("Grid position is occupied! Try again!")
		continue
	clearscreen()
	drawgrid()
	if checkTrio() or checkDraw():
		if checkTrio():
			if turn % 2 == 1:
				print ("Player 1 wins!")
			else:
				print ("Player 2 wins!")
		elif checkDraw():
			print ("Match Drawn!")
		newGame = input("New Game? (Y/N): ")
		newGame = newGame.upper()
		if newGame == 'Y':
			reset()
			clearscreen()
			drawgrid()
		else:
			print ("Goodbye!")
			break
	turn+=1