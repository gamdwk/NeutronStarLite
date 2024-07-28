#i!/bin/bash
mpiexec -np $1 ./build/nts $2
#mpiexec -np 1 ./nts NTS_cora_data.cfg
# mpiexec -np 2 ./build/nts gat_cora.cfg
# mpiexec -np 2 --mca orte_base_allow_run_as_root true gdb -ex "run" --args ./build/nts gat_cora.cfg

