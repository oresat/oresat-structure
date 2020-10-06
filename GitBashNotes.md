# Using Git Bash for the SolidWorks
# You will need to download Git Bash. If you have Windows, Google "Git for Windows"

## first time setup
- go to the repo you wish to clone and click "clone or download" then RIGHT CLICK to copy the link (it will NOT work with ctrl+c)
- type `git clone` = RIGHT CLICK to paste the link, then press enter to copy the repo
- type `cd oresat-structure` = this puts you in the structure repo
- type `git checkout -b typeyourbranchnamehere` = then press enter, This creates a branch like “dev_joe” and switches you to that branch. This branch is a complete clone of master. MAKE SURE YOU DO YOUR WORK IN THIS BRANCH
  
## When you're ready to do work in SolidWorks, make sure your branch is up to date with master. 
- First, navigate to the oresat-structure repo. For me, this command looks like `cd Documents/oresat-structure` but it will look different based on where you put your repo.
- Type `git checkout master` = This puts you on the master branch.
- Type `git pull` = This pulls the latest version of the master branch.
- Type `git checkout insertyourbranchnamehere` = This switches back to your personal branch. For me, this looks like `git checkout dev_emilio`
- Type `git merge master` = This merges master back in to your branch, updating your branch to the latest version of the master branch.
- Type `git push` = This pushes these new changes to your branch.
  
## Now go make things, do work in SolidWorks, etc. You can do this through your file explorer. The repo is placed in the C drive under your username. I recommend pinning this repo to quick start so you can find it easily.

## Once you’re ready to check in
- Fully save everything in solidworks - please do shutdown SolidWorks.
- `git status`=  Shows what’s new, modified, etc. You’ll have red (modified and untracked), and changes ready to to commit are green.
- `git add filename1 filename2` = add file to commit
    - `git add .` =  Only if you want to add all the changes in the directory
- `git status` =  Everything should be green now, except for the files you don’t want to commit.
- `git commit -m “commit message”` = This commit message should briefly describe the work you've done. Something like `git commit -m "Updated card slots"`
- `git status` =  Now it should say you’re ahead of master by one commit
- `git push` =  When you’re ready, do a git push, which saves your branch to the server.

## Once you’re ready to merge with master
- `git checkout master` = swap to master branch
- `git pull` = update master.
- `git checkout insertyourbranchnamehere` = swap back to your branch
- `git merge master` =  This merges master back in your branch. If you experience any problems here, reach out for help.
- `git push` = This saves these changes to your remote branch.
- Now re-open everything in solidworks, make sure there’s nothing broken.

## Once you're done with the updates
- email to Emilio at egizzi@pdx.edu or Hayden at reinhold@pdx.edu so he can update the master assembly. DO NOT update master unless you have permission to do so!

## If something went wrong
-notify Emilio, Hayden, Ryan, and/or Andrew so they can help. 
