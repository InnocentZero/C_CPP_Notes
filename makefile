.DEFAULT_GOAL := git
m ?= arson
git:
	rm -rf ./docs/
	mv ./book/ ./docs
	git add -A
	git commit -m "$m"
	git push origin main

