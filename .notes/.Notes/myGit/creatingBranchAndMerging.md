## The Solo Developer Workflow

Using branches, even when you're alone, is a powerful and professional habit. Here's how it works:

1.  Your `main` branch is your stable base.
2.  When you want to work on a new feature (e.g., adding a contact page), you create a new branch from `main`:
    ```bash
    git checkout -b add-contact-page
    ```
3.  You do all your work and make all your commits on this new `add-contact-page` branch. Your `main` branch remains untouched and stable.
4.  Once the contact page is finished and working perfectly, you switch back to `main` and merge your changes into it:
    ```bash
    # Switch back to the main branch
    git checkout main

    # Merge the new feature into main
    git merge add-contact-page

    # Push the updated main branch to GitHub
    git push origin main
    ```

This workflow keeps your project clean, safe, and organized.
