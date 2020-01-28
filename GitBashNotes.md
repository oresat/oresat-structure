# Using Git Bash for the SolidWorks

## first time setup
- go to the repo you wish to clone and click "clone or download" then RIGHT CLICK to copy the link (it will NOT work with ctrl+c)
- type `git clone` then add a space, RIGHT CLICK to paste the link, then press enter =  to copy the repo
- `git checkout -b` = then add a space and type a name for your branch, then press enter, This creates a branch “dev_yourname” like “dev_joe” and switches you to that branch. This branch is a complete clone of master.
  
## Now go make things, do work in SolidWorks, etc

## Once you’re ready to check in
- Fully save everything in solidworks - please do shutdown SolidWorks.
- `git status`=  Shows what’s new, modified, etc. You’ll have red (modified and untracked), and changes ready to to commit are green.
- `git add filename1 filename2` = add file to commit
    - `git add .` =  Only if you want to add all the changes in the directory
- `git status` =  Everything should be green now, except for the files you don’t want to commit.
- `git commit -m “commit message”`
- `git status` =  Now it should say you’re ahead of master by one commit
- `git push` =  When you’re ready, do a git push, which saves your branch to the server.

## Once you’re ready to merge with master
- `git checkout master` = swap to master branch
- `git pull` = update master.
- `git checkout insertyourbranchnamehere` = swap back to your branch
- `git merge master` =  This merges master back in your branch.
- Now re-open everything in solidworks, make sure there’s nothing broken.

## Once you're done with the updates
- email to Catie at cspivey@pdx.edu so she can update the master assembly. DO NOT update master unless you have permission to do so!

## If something went wrong
-notify Catie, Ryan, and/or Andrew so they can help. 
