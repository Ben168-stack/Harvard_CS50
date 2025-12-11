document.addEventListener('DOMContentLoaded', () => {
  // Header typing animation
  const typedElement = document.querySelector("#typed");
  if (typedElement) {
    new Typed("#typed", {
      strings: ["Software Engineer", "Cloud Solutions Architect", "Web Developer"],
      typeSpeed: 200,
      backSpeed: 100,
      backDelay: 3000,
      loop: true
    });
  }

  // Toggle icon and navbar
  const menuIcon = document.querySelector('#menu-icon');
  const navbar = document.querySelector('.navbar');

  if (menuIcon && navbar) {
    menuIcon.onclick = () => {
      menuIcon.classList.toggle('bx-x');
      navbar.classList.toggle('active');
    };
  }

  // Scroll Section Highlight
  const sections = document.querySelectorAll('section');
  const navLinks = document.querySelectorAll('header nav a');

  window.onscroll = () => {
    const scrollY = window.scrollY;

    sections.forEach(sec => {
      const offset = sec.offsetTop - 100;
      const height = sec.offsetHeight;
      const id = sec.getAttribute('id');

      if (scrollY >= offset && scrollY < offset + height) {
        navLinks.forEach(link => {
          link.classList.remove('active');
          const targetLink = document.querySelector('header nav a[href*=' + id + ']');
          if (targetLink) targetLink.classList.add('active');
        });
      }
    });

    // Sticky header
    const header = document.querySelector('header');
    if (header) {
      header.classList.toggle('sticky', scrollY > 100);
    }

    // Remove toggle icon and navbar when link is clicked (scroll)
    if (menuIcon && navbar) {
      menuIcon.classList.remove('bx-x');
      navbar.classList.remove('active');
    }
  };
});
