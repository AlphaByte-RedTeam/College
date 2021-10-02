import os

class Node:
    def __init__( self, key ):
        self.left = None
        self.right = None
        self.val = key

# In Order Traversal
def inOrder( root ):
    if root:
        inOrder( root.left )            # Left
        print( root.val, end = ' ' )    # Visit
        inOrder( root.right )           # Right

# Post Order Traversal
def postOrder( root ):
    if root:
        postOrder( root.left )          # Left
        postOrder( root.right )         # Right
        print( root.val, end = ' ' )    # Visit

# Pre Order Traversal
def preOrder( root ):
    if root:
        print( root.val, end = ' ' )    # Visit
        preOrder( root.left )           # Left
        preOrder( root.right )          # Right
        
# Gambar 1
root = Node( 10 )
root.left = Node( 9 )
root.right = Node( 8 )
root.left.left = Node( 7 )
root.left.right = Node( 5 )
root.right.left = Node( 6 )
root.right.right = Node( 4 )

os.system( 'cls' )
print( "GAMBAR 1" )
print( "In Order Traversal: " )
inOrder( root )

print( "\nPre Order Traversal: " )
preOrder( root )

print( "\nPost Order Traversal: " )
postOrder( root )

root = Node( 'H' )
root.left = Node( 'A' )
root.right = Node( 'O' )
root.left.left = Node( 'L' )

print( "\n\nGAMBAR 2" )
print( "In Order Traversal: " )
inOrder( root )

print( "\nPre Order Traversal: " )
preOrder( root )

print( "\nPost Order Traversal: " )
postOrder( root )