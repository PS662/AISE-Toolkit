## Notebooks

#### Next-up
- [ ] Openvino examples
- [ ] LLMs
    - [ ] Langchain
    - [ ] Ollama
- [ ] Segmentation
- [ ] Detection
- [ ] CUDA examples

## Playground

### CPP/CPPBuilder

#### Next-up
- [x] Add pimpl, CRTP
- [x] More templating, algos on templated DataStructure
- [x] Take out base object, every builder should be a base object
- [ ] Branch out DS wrappers, clubbed with their algos 
    - [x] Graphs 
        - [x] Remove stl from headers
    - [ ] Matrix
    - [ ] Queues 
    - [ ] Vector
    - [ ] LinkedList
- [ ] Add Algorithms, acts on branched out DS
    - [x] GEMM
    - [ ] CONV
    - [ ] SYCL, Cutlass
    - [ ] Add Cutlass example
    - [ ] Add linear algebra implementation algorithms, i.e: eigenvectors, PCA etc.
    - [ ] AMD Hardware
- [ ] Messaging Builder
- [ ] Threadpool Builder
    - [ ] Async TBB
- [ ] Add benchmarking
  - [ ] Benchmark GEMM and CONV
  - [ ] Benchmark other algos

#### FIXMES
- [ ] Proper access modifiers, remove friend interface class from impl.
- [ ] Unit tests failing, GetInstance does not work, does not add to instance
- [ ] Fix Data Structure interface (should be abstract).
- [x] Only install required libs, deps should not be pulled in
- [x] Add cmake options
- [ ] Fix Doxygen generation
- [ ] CPPBuilder as submodule
- [ ] Namespace

#### Nice to have ADDITIONS
- [ ] JSON/XML handlers
- [ ] Logging
- [ ] Add coverage and finish tests
- [ ] Add Data for unit tests, examples, benchmarking
- [ ] CPack
- [ ] Add Databases
- [ ] Support for cloud
- [ ] SWIG
- [ ] Add forked dependencies
- [ ] Add system design implementations within this framework
- [ ] CICD, Actions

### Python
- [ ] Stage notebooks
- [ ] Celery + Flask
- [ ] PyQT clients

### Toys
- [ ] Add demos

## Scripts
#### Next-up
- [ ] Webscraper
- [ ] Dataset downloader