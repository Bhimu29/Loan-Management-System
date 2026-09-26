// EMI Calculator

async function calculateEMI() {

    let amount =
        Number(document.getElementById("amount").value);

    let interest =
        Number(document.getElementById("interest").value);

    let years =
        Number(document.getElementById("years").value);


    if (amount <= 0 || interest < 0 || years <= 0) {

        document.getElementById("result").innerHTML =
            "Please enter valid values.";

        return;
    }


    // Currently using Personal Loan
    let loanType =
    document.getElementById("loanType").value;


    document.getElementById("result").innerHTML =
        "Calculating EMI...";


    try {

        const response = await fetch(
            "/api/calculate-emi",
            {
                method: "POST",

                headers: {
                    "Content-Type": "application/json"
                },

                body: JSON.stringify({

                    loanType: loanType,
                    amount: amount,
                    interest: interest,
                    years: years

                })
            }
        );


        const data = await response.json();


        if (!data.success) {

            document.getElementById("result").innerHTML =
                data.message;

            return;
        }


        document.getElementById("result").innerHTML =
            "Monthly EMI: ₹" +
            data.emi.toLocaleString("en-IN", {

                maximumFractionDigits: 2

            });

    }

    catch (error) {

        console.error(error);

        document.getElementById("result").innerHTML =
            "Unable to connect to C++ backend.";

    }

}



// Loan Application Form

document
    .getElementById("loanForm")
    .addEventListener("submit", async function(event) {

        event.preventDefault();


        // Get customer details

        const name =
            document.getElementById("name").value;

        const mobile =
            document.getElementById("mobile").value;

        const email =
            document.getElementById("email").value;

        const address =
            document.getElementById("address").value;


        // Get loan details

        const loanType =
            document.getElementById("applicationLoanType").value;

        const amount =
            Number(
                document.getElementById("applicationAmount").value
            );

        const years =
            Number(
                document.getElementById("applicationYears").value
            );


        // Validate

        if (!loanType || amount <= 0 || years <= 0) {

            document.getElementById("message").innerHTML =
                "Please enter valid loan details.";

            return;

        }


        // Show processing message

        document.getElementById("message").innerHTML =
            "Submitting application...";


        try {

            const response = await fetch(
                "/api/apply-loan",
                {

                    method: "POST",

                    headers: {
                        "Content-Type": "application/json"
                    },

                    body: JSON.stringify({

                        name: name,
                        mobile: mobile,
                        email: email,
                        address: address,

                        loanType: loanType,
                        amount: amount,
                        years: years

                    })

                }
            );


            const data =
                await response.json();


            if (!data.success) {

                document.getElementById("message").innerHTML =
                    data.message;

                return;

            }


            document.getElementById("message").innerHTML =
                "✓ Loan application submitted successfully for "
                + name
                + ".";


            // Clear form

            this.reset();


        }

        catch (error) {

            console.error(error);

            document.getElementById("message").innerHTML =
                "Unable to connect to the backend.";

        }

    });
    
    // ========================================
// LOAD LOAN APPLICATIONS
// ========================================

async function loadApplications() {

    const container =
        document.getElementById("applicationsList");

    container.innerHTML =
        "<p>Loading applications...</p>";

    try {

        const response =
            await fetch("/api/applications");

        const data =
            await response.json();


        if (!data.success) {

            container.innerHTML =
                "<p>Unable to load applications.</p>";

            return;
        }


        if (!data.data || data.data.trim() === "") {

            container.innerHTML =
                "<p>No applications found.</p>";

            return;
        }


        // Display applications

        container.innerHTML =
            "<pre>" +
            data.data +
            "</pre>";

    }

    catch (error) {

        console.error(
            "Application loading error:",
            error
        );

        container.innerHTML =
            "<p>Unable to load applications.</p>";
    }
}