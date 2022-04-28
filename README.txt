# CPTS122_PA9
Project Name: Chess Game
Project Description: Basic version of chess
Authors: Ethan Teh, Ethan Lyons
Project Design: April 8, 2022 - April 27, 2022

Testing is performed by commenting out the 2d array in position file, uncommenting new 2d arrays, and performing actions. It is not automated.

There is no polymorphism present. 
The team had planned for using polymorphism for a class "piece", 
creating classes that inherit from piece for each of the individual pieces. 
The subclasses of piece would then be instantiated and arranged in a 2-D array and manipulated that way, 
the functions for checking pieces movements being unique to each subclass of piece, 
and functions relegated to a class with the board to check the state of other pieces.
It would operate very similar to the code implemented currently, in that positions would be passed between
the functions in the order of:
	checking if correct move type
	checking if piece can move to the square legall
	checking if piece causes a Check state on yourself
	checking if piece causes a Check state on opponent (to generate board state)
The class would also hold data like if pieces are in their original positions, etc.

However, due to time constraints the team wanted to focus on creating a program that worked, 
focusing on the rules and usability of the game alongside the graphics and user inputs, 
ensuring that the game is playable.




The chess board is divided into a 8 x 8 grid, labeled A through H
 and 1 through 8, numbers being vertical and letters horizontal

Set the board by distributing pieces on specific spots on the board
 8 white pawns fill the 2nd row, 8 black pawns fill the 7th.
 then, from left to right the white pieces are arranged on 1st row:
 rook, knight, bishop, queen, king, bishop, knight, rook.
 then, from left to right the black pieces are arranged on 8th row:
 rook, knight, bishop, queen, king, bishop, knight, rook.

Pieces are captured when a piece legally moves to the space the
 opposing player was occupying with a piece. You cannot capture
 your own pieces, and tiles cannot be occupied by more than one piece.
Each piece has unique movement opportunities, but pieces can never
 leave the board's tiles unless captured.
 Pawn:
 Pawns can only advance forward in one direction--towards
 the opposing side of the board.
 If a pawn is on its initial square, it can move two spaces
 to advance directly forward.
 Pawns can only advance one square directly forward otherwise.
 Pawns can only capture opposing pieces directly one square 
 diagonally in front while still advancing towards the 
 opposing player's side.
 If a pawn reaches the opposing player's side (row 1 for
 black, row 8 for white), that player can exchange
 the pawn for any non-pawn, non-king piece.
 Pawns cannot take pieces directly in front of them, and
 cannot advance forward if a piece is obstructing
 its path.
 Rook:
 Rooks can move any amount of spaces in directly vertical or
 horizontal direction. This includes forwards,
 backwards, left, and right. Without capturing a piece,
 it can only move to unobstructed squares in its path,
 and cannot move through other pieces to reach a
 destination.
 Rooks can capture pieces anywhere along its path so long as
 it is the first piece encountered. It cannot move
 through pieces to reach a destination.
 Knight:
 Knights move in an "L" shaped pattern. This means it can move
 two squares in any one direction except diagonal, and
 an additional square in a perpendicular direction.
 ie: moving forwards two, right one; moving forwards one,
 left two; moving backwards two, right one, etc...
 Knights can travel through pieces to reach their destination
 Knights can only capture pieces they arrive at as a destination,
 not any pieces in a potential path to the destination.
 Bishop:
 Bishops can move any amount of spaces diagonally in any direction.
 This means it is moving in the horizontal direction the
 same amount it is traveling vertically. Without capturing
 a piece, it can only move to unobstructed squares in its
 path, and cannot move through other pieces to reach a
 destination.
 Bishops can capture pieces anywhere along its path so long as
 it is the first piece encountered. It cannot move
 through pieces to reach a destination.
 Queen:
 Queens can move any amount of spaces in a diagonal, horizontal,
 or vertical direction (similar to bishops and rooks).
 Also similarly, without capturing a piece, it can only
 move to unobstructed squares in its path, and cannot move
 through other pieces to reach a destination.
 Queens can capture pieces anywhere along its path so long as it is
 the first piece encountered. it cannot move through pieces
 to reach a destination.
 King:
 Kings can move one space at a time in a diagonal, horizontal,
 or vertical direction. It cannot move to spaces occupied
 by your own pieces.
 Kings cannot move to squares where it has the potential to be
 directly captured by other pieces.
 Kings can capture pieces around it, so long as it doesn't arrive
 to a square where it has the potential to be directly
 captured by other pieces.
 Kings are considered in "Check" if on a player's turn, the king is
 actively available to be captured by the opposing player's
 next move.
 Castling involves moving the king two spaces to the left or right.
 The rook will then move across and to the other side of the 
 king. This can only be done if there are no pieces obstructing
 either the rook or the king, and neither the king or the rook
 have moved from their original squares at the start of
 the game.

White will always move first.

The objective of chess is to "Checkmate" the opponent.
 This is achieved by putting the opposing king in Check, mentioned above.
 If there is a Check, the opposing player must remove the check, or else
 they lose the game, called a Checkmate. Checks can be removed by 
 capturing a piece causing a check, obstructing the path of a piece 
 causing a check, or moving the king out of the pieces path of a 
 check.
 If either player cannot make any legal moves, the game ends in an immediate 
 draw. This is called a stalemate.

There are other rules and play modes present in chess, however were not addressed 
 for simplicity.
These rules include:
 En passant:
 The capture by a pawn of a horizontally adjacent enemy 
 pawn that has just made a two-square move.
 3-fold repetition:
 A tie caused by players repeating the same set of moves three times.
 50-move rule:
 A tie caused by neither player capturing a piece or moving a pawn
 for fifty moves.
 Dead position:
 If neither player has the potential to reach a checkmate, the game
 is tied.
 Resignation:
 When a player forfeits a game by choice.
 Draw offer / Draw offer accepted.
 To offer a tie to the opponent, then make a move. If the opponent
 accepts, the game is tied, otherwise the game resumes.
These game modes include:
 Time control:
 A mode where players have an allotted time bank. During a player's
 turn, the time bank slowly expires until the player makes a legal
 move, or the bank expires, causing an immediate loss.
 Different time control variants have different starting time bank
 amounts, and varying increases of bank time after a player moves.

Link to demonstration video (only accessible through One Drives in the WSU domain). If replacement link is needed, please contact me at ethan.j.lyons@wsu.edu so I can directly share the file.
https://emailwsu-my.sharepoint.com/:v:/g/personal/ethan_j_lyons_wsu_edu/Ed2EtpHvxjBAsGDiHj9mP7IBn8_sDXfRHgsNDkKEmazQIg?e=HI0zHO


