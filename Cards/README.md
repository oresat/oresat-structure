# OreSat Generic Card PCB


The Generic card PCB definition part is based off of the frame dimension, but is not using reference to OreSat's Frame asembly. Every generic card PCB origin is the center of OreSat if view form a Z plane. This decision of non-refernce was made to remove the chance of cycle of refernces in all OreSat's assemblies (SolidWork usally doesn't allow this, but it is still posible). Also since multiple people need to edit the PCB cards, a single part with configurations for each PCB card will not work. Therefor OreSat's PCB cards will use a generic card PCB definition part and if a system card assembly needs a card with extra features, make a derived card (see steps below). The generic card PCB definition has two configuration, default config has no RF connector slots and RF config has slots for RF connectors. If no feature need to be added to a new PCB card just use the generic card PCB definition in the assembly.


## To make a derived card PCB from the generic card PCB definition:
- Make a new part for the new card PCB.
- Use Insert/Part and find the generic card definition part.
- Make sure Solid bodies, Planes, Unasbsorbed sketches and Locate part with Move/Copy feature are all turn on. 
- Place card or click the green arrow.
- Use the coincident mates to mate all plane together (card def right plane to part right plane, etc).
- Click the green arrow.
- The origin of the part should match the origin of the card.
	- If any of the feature need to be turn off/on or the mate are wrong, edit part can be used.
- Select configuration need (right click on part, click Configure Feature, select config wanted).
	- Default does not have slots for RF connectors.
	- RF has the slots for the RF connectors.
- Add any feature as needed (holes, etc) and define the location of feature based of the origin of the part (center of OreSat).


## If the generic card PCB definition needs to be change: 
- Readd the part to the Frame assembly.
- Mate the card front plane and the frame assembly front plane (to keep origin of card in OreSat's center).
- Mate the card right plane and the frame assembly right plane (to keep origin of card in OreSat's center).
- Mate the card into as slot (this is optional, but can be useful).
- Do any edits needed (the card definition can have no dimension or can be fixed, no dimension version can be modified easier).
- Save generic card PCB definition.
- Remove the generic card from Frame assembly.
- Open all card assembly and fix any problem the edit made.

