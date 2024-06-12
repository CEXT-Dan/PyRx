def CheckTestResults(path):
    with open(path) as testFile:
        testPass = True

        for line in testFile:
            if line[0:4] == "test":
                if line[-9:] == "... FAIL\n":
                    testPass = False
                    print("\n", line.rstrip(" ... FAIL\n"), "test failed")

        if testPass == True:
            print("\nPASS")
        
        else:
            print("\nFAIL")

        return testPass

CheckTestResults("testResults/tout-ARX25-2024-06-12.txt")