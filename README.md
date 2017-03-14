# oresat-structure
Mechanical structure for OreSat

CAD requires <a href="https://github.com/oresat/reaction-wheels">Reaction-Wheels</a> be cloned into the same directory

### TODO:
- [ ] Properly migrate individual CAD files into Solidworks.  
_(open `Rev 0.5/2u_cubesat_v0_5.stp` and export each part to the appropriate spot in `Rev 0.5 Migrated/`)_
	- REACTION WHEELS
		- [ ] REACTION WHEEL MOUNT
		- MOTOR WITH MASS
			- BRUSHLESS MOTOR
				- [ ] BRUSHLESS MOTOR TOP
				- [ ] BRUSHLESS MOTOR BOTTOM
				- [ ] BRUSHLESS MOTOR COIL
			- [ ] EXTRA MASS PART
	- HELICAL CAN
		- [ ] 100211587UGM000_B.2
		- [ ] MMCX FEMALE
		- [ ] MODULE PLACEHOLDER PCB WITHRF
		- [ ] HELICAL CAN REV 0 1
	- SOLAR PANEL 1U
		- [ ] 1522020X601XXX_100210477MOD000B
		- [ ] BOSS EXTRUDE 5
	- BACKPLANE V4 POPULATED
		- [ ] MMCX CONNECTOR PLUG
		- [ ] 1521040X401XXX_100632479MOD0_1
		- [ ] BACKPLANE V4
		- [ ] STUFF (might be unnecessary)
	- [ ] SPACE FOAM
	- STRUCTURE
		- [ ] M2.5 10 MM
		- [ ] SIDES
		- [ ] FRONT
		- [ ] BACK
	- CARD MODULES
		-  CARD GENERIC
		    	- [ ] 100211647UGM000_B
			- [ ] MMCX FEMALE
			- [ ] MODULE PLACEHOLDER PCB WITHRF 2
		- CARD LOWER
			- [ ] MMCX FEMALE
			- [ ] MODULE PLACEHOLDER PCB WITHRF 4
		    	- [ ] 100211647UGM000_B
		- CARD CAMERA
			- [ ] CAMERA
			- [ ] MMCX FEMALE
			- [ ] MODULE PLACEHOLDER PCB WITHRF 3
			- [ ] 100211647UGM000_B
	- ANTENNA SOLARPANEL UNWRAPPED
		- CARD TOP
		- [ ] ANTENNA WRAP GUIDE
		- ANTENNA ASSEMBLY UNWRAPPED
		- [ ] SOLAR PANEL 1U Z
- [ ] Properly mate/parameterize all necessary structures
- [ ] Organize file structure into something reasonable
- [ ] Discuss endcap mounting
- [ ] Form subgroup to work on antenna deployment
- [ ] Setup submodule(s) to point to the reaction wheel (and airframe?) repo.
