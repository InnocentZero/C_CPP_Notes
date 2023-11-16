.DEFAULT_GOAL := git
git:
	mdbook clean
	rm -rf ./docs/
	mdbook build
	mv ./book/ ./docs
	git add -A
	@read -p "Commit message: " m; \
	git commit -m $$m

