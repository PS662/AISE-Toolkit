BUILDER_SCRIPT_PATH = scripts/BuilderGenerator.sh
BUILD_DIR = ../../build

.PHONY: all builder-generator test examples algorithms clean

# The all target
all: algorithms examples test

# The builder target
builder-generator:
	@if [ -z "$(PROJECT)" ]; then \
		echo "Please provide PROJECT name, e.g., 'make builder-generator PROJECT=myProject SOURCE_NAMES=\"Sample1 Sample2\"'"; \
		exit 1; \
	fi
	@if [ -z "$(SOURCE_NAMES)" ]; then \
		echo "Please provide SOURCE_NAMES, e.g., 'make builder-generator PROJECT=myProject SOURCE_NAMES=\"Sample1 Sample2\"'"; \
		exit 1; \
	fi
	@$(BUILDER_SCRIPT_PATH) $(PROJECT) $(SOURCE_NAMES)

# The test target
test:
	@cmake -S . -B $(BUILD_DIR) -DWITH_TESTS=ON
	@cmake --build $(BUILD_DIR)
	@cd $(BUILD_DIR) && ctest --verbose

# The examples target
examples:
	@cmake -S . -B $(BUILD_DIR) -DWITH_EXAMPLES=ON
	@cmake --build $(BUILD_DIR)

algorithms:
	@cmake -S . -B $(BUILD_DIR) -DWITH_Algorithms=ON -DWITH_EXAMPLES=OFF -DWITH_TESTS=OFF -DWITH_Builder1=OFF -DWITH_Builder2=OFF
	@cmake --build $(BUILD_DIR)

# The install target to install artifacts
install:
	@cmake --build $(BUILD_DIR) --target install

# The clean target to clean up build artifacts
clean:
	@rm -rf $(BUILD_DIR)
	@echo "Build directory cleaned"
