
{   //* Basic decision branching demo
    let age = 18;

    if (age >= 18) {
        console.log("Eligible for onboarding into the system.");
    } else {
        console.log("Access denied — prerequisite age not met.");
    }
}

{   //* // if else ladder

    let marks = 72;

    if (marks >= 90) {
        console.log("Rating: A — outstanding performance.");
    } else if (marks >= 75) {
        console.log("Rating: B — above benchmark.");
    } else if (marks >= 50) {
        console.log("Rating: C — meets expectations.");
    } else {
        console.log("Rating: D — remediation required.");
    }

}

{   //* // Decision tree with layered conditions

    let userRole = "admin";
    let status = "active";

    if (userRole === "admin") {
        if (status === "active") {
            console.log("Admin privileges granted.");
        } else {
            console.log("Admin identified but inactive — access blocked.");
        }
    } else {
        console.log("Not an admin — route to standard workflow.");
    }

}

{   //* / Cleaner alternative to multi-branch checks

    let department = "IT";

    switch (department) {
        case "HR":
            console.log("Redirecting to Human Resources.");
            break;

        case "FINANCE":
            console.log("Redirecting to Finance operations.");
            break;

        case "IT":
            console.log("Redirecting to Technology stack.");
            break;

        default:
            console.log("Unrecognized vertical — validation required.");
    }

}

{   //* Inline decision expression for rapid evaluation

    let loggedIn = true;

    let message = loggedIn
        ? "User session validated."
        : "Authentication pending.";

    console.log(message);

}

{    //*  short_circuiting.js
    // Logical operators doubling as conditional triggers

    let username = null;

    // If username is falsy, fallback allocates a default value
    let displayName = username || "Guest User";

    console.log("Welcome :", displayName);

}

{ //! conditional_expression_examples.js
    // Central showcase of conditional constructs in action

    let a = 10;
    let b = 20;

    console.log("Max value:", (a > b ? a : b));

    // Guard conditions
    b && console.log("Value of B exists :", b);

    // Nullish coalescing — modern conditional evaluation
    let input = null;
    console.log("Effective value:", input ?? "No input received.");

}

