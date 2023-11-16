.DEFAULT_GOAL := git
m ?= arson
git:
	mdbook clean
	rm -rf ./docs/
	mdbook build
	mv ./book/ ./docs
	git add -A
	@read -p "Commit message: " m; \
	git commit -m "$m"
	git push origin main

