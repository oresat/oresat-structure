# oresat-structure
Mechanical structure for OreSat

CAD requires <a href="https://github.com/oresat/reaction-wheels">Reaction-Wheels</a> be cloned into the same directory

## TODO:  
### CAD migration
_Please start at the top of the list. Lower items in the CAD migration typically depend on higher items._
- [ ] Organize file structure into something reasonable
- [ ] Identify which parts have already been migrated.
	- [ ] `Cards/Solar/Board.sldprt`
	- [ ] `Cards/Solar/12pin_connector.sldprt`
	- [ ] `Cards/Solar/ALTA-FIVE-CELL-THROUGH-SLOT.sldprt`
- [ ] migrate individual CAD files into Solidworks.  
_(open `Rev 0.5/2u_cubesat_v0_5.stp` and export each part to the appropriate spot in `Rev 0.5 Migrated/`)_
	- REACTION WHEELS  
	_(These parts should come from the reaction wheels repo. They are also going to change at some point, so don't stress too much about mating them to the OreSat assembly.)_
		- [ ] Add `oresat/reaction-wheels` as a submodule?  
		_I'm not sure if it's better to add it as a submodule or just have the SW assemblies link outside of the structure repo. The submodule is marginally more learning curve for the MME types, but the other way is less self-contained._
		- [ ] Link to the appropriate parts and/or subassemblies in the OreSat SolidWorks assembly.
	- HELICAL CAN _(This will have to be modified, so it's not super necessary to migrate.)_
		- [ ] 100211587UGM000_B.2
			- [ ] Identify what part this is.
		- [X] MMCX FEMALE
		- [ ] MODULE PLACEHOLDER PCB WITHRF
		- [ ] HELICAL CAN REV 0 1
	- SOLAR PANEL 1U
		- [ ] 1522020X601XXX_100210477MOD000B
			- [ ] Identify what part this is.
		- [X] BOSS EXTRUDE 5
	- BACKPLANE V4 POPULATED
		- [X] MMCX CONNECTOR PLUG
		- [ ] 1521040X401XXX_100632479MOD0_1
			- [ ] Identify what part this is.
		- [ ] BACKPLANE V4
		- [ ] STUFF (might be unnecessary)
	- [ ] SPACE FOAM
	- STRUCTURE
		- [X] M2.5 10 MM
		- [X] SIDES
		- [X] FRONT
		- [X] BACK
	- CARD MODULES
		-  CARD GENERIC
			- [ ] 100211647UGM000_B
				- [ ] Identify what part this is.
			- [X] MMCX FEMALE
			- [X] MODULE PLACEHOLDER PCB WITHRF 2
		- CARD LOWER
			- [X] MMCX FEMALE
			- [ ] MODULE PLACEHOLDER PCB WITHRF 4
		    	- [ ] 100211647UGM000_B
				- [ ] Identify what part this is.
		- CARD CAMERA
			- [X] CAMERA
			- [X] MMCX FEMALE
			- [ ] MODULE PLACEHOLDER PCB WITHRF 3
			- [ ] 100211647UGM000_B
				- [ ] Identify what part this is.
	- ANTENNA SOLARPANEL UNWRAPPED
		- CARD TOP
			- [ ] MODULE PLACEHOLDER PCB WITHRF
			- [ ] 100211587UMG000_B
				- [ ] Identify what part this is.
		- [ ] ANTENNA WRAP GUIDE _(This will have to be modified, so it's not super necessary to migrate.)_
		- ANTENNA ASSEMBLY UNWRAPPED _(This will have to be modified, so it's not super necessary to migrate.)_
			- [ ] 163 MM ANTENNA
			- [ ] 163 MM ANTENNA WRAPPED
			- [ ] ANTENNA GUIDE V2
		- [ ] SOLAR PANEL 1U Z
		
#### Only after _all_ of the individual parts have been migrated:
- [ ] Rename migrated parts, if necessary.
- [ ] Mate/parameterize the subassemblies. _(smallest first)_

### general
- [ ] Discuss endcap mounting.
- [ ] Form subgroup to work on antenna deployment.
