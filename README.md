# Spell checker

Your goal is to implement a spelling checker. You should correct words by finding words in the dictionary that are no more than two edits away from the input.

Here, an edit is either:
* Inserting a single letter
* Deleting a single letter

wth restriction that
* If the edits are both insertions or both deletions, they ay not be of adjacent characters.

The input will consist of a dictionary followed by a sequence of possibly misspelt words. Both contain words (strings of letters) of up to 50 characters. The dictionary, in free format, is followed by a line containing just the string „=\==‟. After this, there will be zero or more text lines containing words followed again by a line containing the string „=\==‟. The input is caseinsensitive; print corrections from the dictionary in the case they appear in the dictionary and unchanged words from the text lines in their original case as well.

As output, you should print the text lines with whitespace intact,with the following changes on each word, W:
* If W is in the dictionary, print it as is.
* Otherwise, if W is not in the dictionary,
	- If no corrections can be fount, print "{W?}".
	- Ignore any corrections that require two edits if there is at least one that requires only one edit
	- If exatly one correction is left, print that word.
	- If more then one possible correction is left, print the set of corrections as "{W1 W2 ...}, in the order they appear in the dictionary.

Don't forget that dictionary and text size might be big enough to raise perforance issues.

## Example

Input | Output
:-|:-
rain spain plain plaint pain main mainly <br/> the in on fall falls his was  <br/>=== <br/> hte rame in pain fells <br/> mainy oon teh lain <br/> was hints pliant <br/> ===| the {rame?} in pain falls <br/>{main mainly} on the plain <br/>was {hints?} plaint

	
