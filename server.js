const express = require("express");
const path = require("path");
const { execFile } = require("child_process");
const fs = require("fs");

const app = express();


// ========================================
// PORT
// ========================================

const PORT = process.env.PORT || 3000;


// ========================================
// MIDDLEWARE
// ========================================

app.use(express.json());

app.use(express.urlencoded({ extended: true }));

app.use(express.static(__dirname));


// ========================================
// C++ PROGRAM LOCATION
// ========================================

// Windows:
//     C++/api.exe
//
// Render/Linux:
//     C++/api

const cppProgram =
    process.platform === "win32"
        ? path.join(__dirname, "C++", "api.exe")
        : path.join(__dirname, "C++", "api");


// ========================================
// CHECK C++ PROGRAM
// ========================================

console.log("----------------------------------------");
console.log("C++ Program:");
console.log(cppProgram);
console.log("----------------------------------------");


// ========================================
// TEST C++ CONNECTION
// ========================================

app.get("/api/cpp-test", (req, res) => {

    execFile(

        cppProgram,

        [
            "personal",
            "500000",
            "8.5",
            "5"
        ],

        (error, stdout, stderr) => {

            if (error) {

                console.error("C++ Error:", error);
                console.error("C++ Output:", stderr);

                return res.status(500).json({

                    success: false,

                    message:
                        "C++ calculation failed.",

                    error:
                        stderr || error.message

                });

            }


            const emi =
                Number(stdout.trim());


            if (isNaN(emi)) {

                return res.status(500).json({

                    success: false,

                    message:
                        "Invalid response from C++."

                });

            }


            res.json({

                success: true,

                message:
                    "C++ calculated EMI successfully.",

                emi: emi

            });

        }

    );

});


// ========================================
// CALCULATE EMI USING C++
// ========================================

app.post("/api/calculate-emi", (req, res) => {

    const {

        loanType,
        amount,
        interest,
        years

    } = req.body;


    // Validate input

    if (

        !loanType ||

        Number(amount) <= 0 ||

        Number(interest) < 0 ||

        Number(years) <= 0

    ) {

        return res.status(400).json({

            success: false,

            message:
                "Please provide valid loan details."

        });

    }


    execFile(

        cppProgram,

        [

            String(loanType),

            String(amount),

            String(interest),

            String(years)

        ],

        (error, stdout, stderr) => {

            if (error) {

                console.error(
                    "C++ EMI Error:",
                    error
                );

                console.error(
                    "C++ Output:",
                    stderr
                );

                return res.status(500).json({

                    success: false,

                    message:
                        "C++ calculation failed."

                });

            }


            const emi =
                Number(stdout.trim());


            if (isNaN(emi)) {

                return res.status(500).json({

                    success: false,

                    message:
                        "Invalid response from C++."

                });

            }


            res.json({

                success: true,

                loanType: loanType,

                amount: Number(amount),

                interest: Number(interest),

                years: Number(years),

                emi: emi

            });

        }

    );

});


// ========================================
// LOAN APPLICATION
// ========================================

app.post("/api/apply-loan", (req, res) => {

    const {

        name,
        mobile,
        email,
        address,
        loanType,
        amount,
        years

    } = req.body;


    // ========================================
    // VALIDATE CUSTOMER DETAILS
    // ========================================

    if (

        !name ||
        !mobile ||
        !email ||
        !address

    ) {

        return res.status(400).json({

            success: false,

            message:
                "Please fill all customer details."

        });

    }


    // ========================================
    // VALIDATE LOAN DETAILS
    // ========================================

    if (

        !loanType ||

        Number(amount) <= 0 ||

        Number(years) <= 0

    ) {

        return res.status(400).json({

            success: false,

            message:
                "Please enter valid loan details."

        });

    }


    // ========================================
    // APPLICATION FILE
    // ========================================

    const applicationFile =
        path.join(
            __dirname,
            "applications.txt"
        );


    // ========================================
    // GENERATE APPLICATION ID
    // ========================================

    let applicationId = 1001;


    if (
        fs.existsSync(applicationFile)
    ) {

        try {

            const existingData =
                fs.readFileSync(
                    applicationFile,
                    "utf8"
                );


            const matches =
                existingData.match(
                    /ID:(\d+)/g
                );


            if (
                matches &&
                matches.length > 0
            ) {

                const ids =
                    matches.map(
                        id =>
                            parseInt(
                                id.replace(
                                    "ID:",
                                    ""
                                )
                            )
                    );


                applicationId =
                    Math.max(...ids) + 1;

            }

        }

        catch (error) {

            console.error(
                "Error reading application file:",
                error
            );

        }

    }


    console.log(
        "New Application ID:",
        applicationId
    );


    // ========================================
    // RUN C++ LOAN APPLICATION
    // ========================================

    execFile(

        cppProgram,

        [

            "apply",

            String(applicationId),

            String(name),

            String(mobile),

            String(email),

            String(address),

            String(loanType),

            String(amount),

            "8.5",

            String(years)

        ],

        (error, stdout, stderr) => {


            // ========================================
            // HANDLE C++ ERROR
            // ========================================

            if (error) {

                console.error(
                    "C++ Application Error:",
                    error
                );

                console.error(
                    "C++ Output:",
                    stderr
                );

                return res.status(500).json({

                    success: false,

                    message:
                        "C++ loan processing failed.",

                    error:
                        stderr || error.message

                });

            }


            // ========================================
            // DISPLAY RESULT
            // ========================================

            console.log(
                "--------------------------------"
            );

            console.log(
                "NEW LOAN APPLICATION"
            );

            console.log(
                "--------------------------------"
            );

            console.log(stdout);

            console.log(
                "--------------------------------"
            );


            // ========================================
            // SAVE APPLICATION
            // ========================================

            try {

                fs.appendFileSync(

                    applicationFile,

                    stdout +
                    "\n--------------------------------\n"

                );


                console.log(
                    "Application saved successfully."
                );

            }

            catch (fileError) {

                console.error(
                    "File saving error:",
                    fileError
                );

            }


            // ========================================
            // SEND RESULT TO WEBSITE
            // ========================================

            res.json({

                success: true,

                message:
                    "Loan application submitted successfully.",

                applicationId:
                    applicationId,

                customer: {

                    name:
                        name,

                    mobile:
                        mobile,

                    email:
                        email,

                    address:
                        address

                },

                loan: {

                    type:
                        loanType,

                    amount:
                        Number(amount),

                    years:
                        Number(years),

                    emi:
                        extractEMI(stdout)

                },

                result:
                    stdout

            });

        }

    );

});


// ========================================
// GET ALL APPLICATIONS
// ========================================


// ========================================
// EXTRACT EMI FROM C++ RESULT
// ========================================

function extractEMI(text) {

    const match =
        text.match(
            /EMI:([0-9.]+)/
        );


    if (match) {

        return Number(match[1]);

    }


    return 0;

}


// ========================================
// START SERVER
// ========================================

app.listen(

    PORT,

    "0.0.0.0",

    () => {

        console.log(
            "----------------------------------------"
        );

        console.log(
            " Loan Management System"
        );

        console.log(
            "----------------------------------------"
        );

        console.log(
            `Server running on port ${PORT}`
        );

        console.log(
            "----------------------------------------"
        );

    }

);