# CMake generated Testfile for 
# Source directory: D:/Github/dilithium/ref
# Build directory: D:/Github/dilithium/build/ref
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(dilithium2_ref "D:/Github/dilithium/build/ref/test_dilithium2_ref.exe")
set_tests_properties(dilithium2_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;78;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(dilithium2_ref_copy "D:/Github/dilithium/build/ref/test_dilithium2_ref_copy.exe")
set_tests_properties(dilithium2_ref_copy PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;79;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(dilithium2aes_ref "D:/Github/dilithium/build/ref/test_dilithium2aes_ref.exe")
set_tests_properties(dilithium2aes_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;80;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(dilithium3_ref "D:/Github/dilithium/build/ref/test_dilithium3_ref.exe")
set_tests_properties(dilithium3_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;81;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(dilithium3aes_ref "D:/Github/dilithium/build/ref/test_dilithium3aes_ref.exe")
set_tests_properties(dilithium3aes_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;82;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(dilithium5_ref "D:/Github/dilithium/build/ref/test_dilithium5_ref.exe")
set_tests_properties(dilithium5_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;83;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(dilithium5aes_ref "D:/Github/dilithium/build/ref/test_dilithium5aes_ref.exe")
set_tests_properties(dilithium5aes_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;84;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(vectors2_ref "PowerShell" "-Command" "D:/Github/dilithium/build/ref/test_vectors2_ref.exe | dos2unix > tvecs2")
set_tests_properties(vectors2_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;87;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(vectors2aes_ref "PowerShell" "-Command" "D:/Github/dilithium/build/ref/test_vectors2aes_ref.exe | dos2unix > tvecs2aes")
set_tests_properties(vectors2aes_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;88;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(vectors3_ref "PowerShell" "-Command" "D:/Github/dilithium/build/ref/test_vectors3_ref.exe | dos2unix > tvecs3")
set_tests_properties(vectors3_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;89;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(vectors3aes_ref "PowerShell" "-Command" "D:/Github/dilithium/build/ref/test_vectors3aes_ref.exe | dos2unix > tvecs3aes")
set_tests_properties(vectors3aes_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;90;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(vectors5_ref "PowerShell" "-Command" "D:/Github/dilithium/build/ref/test_vectors5_ref.exe | dos2unix > tvecs5")
set_tests_properties(vectors5_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;91;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(vectors5aes_ref "PowerShell" "-Command" "D:/Github/dilithium/build/ref/test_vectors5aes_ref.exe | dos2unix > tvecs5aes")
set_tests_properties(vectors5aes_ref PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;92;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
add_test(hashes "sha256sum" "-c" "../../SHA256SUMS")
set_tests_properties(hashes PROPERTIES  _BACKTRACE_TRIPLES "D:/Github/dilithium/ref/CMakeLists.txt;102;add_test;D:/Github/dilithium/ref/CMakeLists.txt;0;")
